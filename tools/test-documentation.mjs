import fs from 'node:fs';
import path from 'node:path';
import assert from 'node:assert/strict';
import { fileURLToPath } from 'node:url';

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
let links = 0;
const documents = fs.readdirSync(path.join(root, 'docs')).filter(name => name.endsWith('.html'));
assert.equal(documents.length, 12, 'Expected six readmes and six FAQs');
for (const name of documents) {
  const file = path.join(root, 'docs', name);
  const html = fs.readFileSync(file, 'utf8');
  assert.match(html, /<html lang="[a-z]{2}">/, `${name}: missing language`);
  assert.match(html, /<main id="main-content">/, `${name}: missing main landmark`);
  assert.match(html, /<h1>/, `${name}: missing heading`);
  assert.equal([...html.matchAll(/<h1>/g)].length, 1, `${name}: expected one document title`);
  assert.match(html, /<nav aria-label="[^"]+">/, `${name}: missing contents landmark`);
  const ids = [...html.matchAll(/\bid="([^"]+)"/g)].map(match => match[1]);
  assert.equal(new Set(ids).size, ids.length, `${name}: duplicate anchor`);
  let previousLevel = 0;
  for (const [, level] of html.matchAll(/<h([1-6])\b/g)) {
    assert.ok(Number(level) <= previousLevel + 1, `${name}: skipped heading level`);
    previousLevel = Number(level);
  }
  for (const [, value] of html.matchAll(/(?:href|src)="([^"]+)"/g)) {
    if (/^[a-z][a-z\d+.-]*:/i.test(value)) continue;
    const [relative, fragment] = value.split('#');
    const target = relative ? path.resolve(path.dirname(file), decodeURIComponent(relative)) : file;
    assert.ok(fs.existsSync(target), `${name}: missing target ${value}`);
    assert.ok(!target.endsWith('.md'), `${name}: links to raw Markdown ${value}`);
    if (fragment && target.endsWith('.html')) {
      assert.ok(fs.readFileSync(target, 'utf8').includes(`id="${decodeURIComponent(fragment)}"`), `${name}: missing anchor ${value}`);
    }
    ++links;
  }
}
// Each spoken message must have all six translations and the same arguments.
const messages = fs.readFileSync(path.join(root, 'src', 'meter_measurement_text.h'), 'utf8');
let rows = 0;
for (const row of messages.matchAll(/^\s*\{(".*")\},?$/gm)) {
  const translations = JSON.parse(`[${row[1]}]`);
  assert.equal(translations.length, 6);
  const parameters = value => [...value.matchAll(/%\d+/g)].map(match => match[0]).sort();
  for (const translation of translations) {
    assert.ok(translation.trim());
    assert.deepEqual(parameters(translation), parameters(translations[0]));
  }
  ++rows;
}
assert.equal(rows, 20);
console.log(`${documents.length} HTML documents, ${links} local links, and ${rows} translated meter messages checked.`);
