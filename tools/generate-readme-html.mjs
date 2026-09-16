import fs from "node:fs";

const markedModule = await import(process.env.MARKED_MODULE ?? "marked");
const { marked } = markedModule;

const documents = [
  ["PROJECT_README.md", "docs/README.en-US.html", "en", "Skip to content"],
  ["docs/README.de-DE.md", "docs/README.de-DE.html", "de", "Zum Inhalt springen"],
  ["docs/README.es-ES.md", "docs/README.es-ES.html", "es", "Saltar al contenido"],
  ["docs/README.fr-FR.md", "docs/README.fr-FR.html", "fr", "Aller au contenu"],
  ["docs/README.ru-RU.md", "docs/README.ru-RU.html", "ru", "Перейти к содержимому"],
  ["docs/README.uk-UA.md", "docs/README.uk-UA.html", "uk", "Перейти до вмісту"],
  ["docs/Sound-Features-FAQ.en-US.md", "docs/Sound-Features-FAQ.en-US.html", "en", "Skip to content"],
  ["docs/Sound-Features-FAQ.de-DE.md", "docs/Sound-Features-FAQ.de-DE.html", "de", "Zum Inhalt springen"],
  ["docs/Sound-Features-FAQ.es-ES.md", "docs/Sound-Features-FAQ.es-ES.html", "es", "Saltar al contenido"],
  ["docs/Sound-Features-FAQ.fr-FR.md", "docs/Sound-Features-FAQ.fr-FR.html", "fr", "Aller au contenu"],
  ["docs/Sound-Features-FAQ.ru-RU.md", "docs/Sound-Features-FAQ.ru-RU.html", "ru", "Перейти к содержимому"],
  ["docs/Sound-Features-FAQ.uk-UA.md", "docs/Sound-Features-FAQ.uk-UA.html", "uk", "Перейти до вмісту"],
];

const css = `
  :root { color-scheme: light dark; }
  * { box-sizing: border-box; }
  body {
    margin: 0;
    font-family: system-ui, -apple-system, "Segoe UI", sans-serif;
    font-size: 1rem;
    line-height: 1.6;
    background: Canvas;
    color: CanvasText;
  }
  main { max-width: 76ch; margin: 0 auto; padding: 1.5rem; }
  h1, h2, h3 { line-height: 1.25; }
  h2 { margin-top: 2rem; }
  li + li { margin-top: .35rem; }
  nav { border-block: 1px solid GrayText; padding-block: 1rem; }
  a { color: LinkText; text-decoration: underline; text-underline-offset: .15em; }
  a:focus-visible { outline: 3px solid Highlight; outline-offset: 3px; }
  .skip-link {
    position: absolute;
    left: .5rem;
    top: -5rem;
    padding: .75rem;
    background: Canvas;
    color: CanvasText;
    border: 2px solid CanvasText;
  }
  .skip-link:focus { top: .5rem; }
  code { overflow-wrap: anywhere; }
  img { max-width: 100%; height: auto; }
  @media (prefers-reduced-motion: reduce) {
    * { scroll-behavior: auto !important; }
  }
`;

function escapeHtml(value) {
  return value
    .replaceAll("&", "&amp;")
    .replaceAll("<", "&lt;")
    .replaceAll(">", "&gt;")
    .replaceAll('"', "&quot;");
}

const contentsLabels = { en: 'Contents', de: 'Inhalt', es: 'Contenido', fr: 'Sommaire', ru: 'Содержание', uk: 'Зміст' };

for (const [sourcePath, destinationPath, language, skipText] of documents) {
  const source = fs.readFileSync(sourcePath, "utf8");
  let body = marked.parse(source, { gfm: true });
  body = body.replaceAll('src="assets/', 'src="../assets/');
  if (sourcePath === "PROJECT_README.md") {
    body = body.replaceAll('href="docs/', 'href="').replaceAll('href="LICENSE', 'href="../LICENSE');
  }

  body = body.replaceAll('href="../README.md"', 'href="README.en-US.html"');
  body = body.replace(/href="(README\.[a-z]{2}-[A-Z]{2})\.md"/g, 'href="$1.html"');
  const sections = [];
  body = body.replace(/<h2>(.*?)<\/h2>/g, (_, heading) => {
    const id = `section-${sections.length + 1}`;
    sections.push(`<li><a href="#${id}">${heading}</a></li>`);
    return `<h2 id="${id}">${heading}</h2>`;
  });
  const contents = `<nav aria-label="${contentsLabels[language]}"><h2>${contentsLabels[language]}</h2><ul>${sections.join('\n')}</ul></nav>`;
  // Keep the title and introduction before the navigation landmark.
  body = body.replace(/<h2 id="section-1">/, `${contents}\n<h2 id="section-1">`);
  const titleMatch = source.match(/^#\s+(.+)$/m);
  const title = titleMatch?.[1] ?? "Accessible Studio";
  const html = `<!doctype html>
<html lang="${language}">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>${escapeHtml(title)}</title>
<style>${css}</style>
</head>
<body>
<a class="skip-link" href="#main-content">${escapeHtml(skipText)}</a>
<main id="main-content">
${body}</main>
</body>
</html>
`;

  fs.writeFileSync(destinationPath, html, "utf8");
  console.log(destinationPath);
}
