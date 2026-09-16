// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once
namespace ReliabilityText {
inline QString StaleEditor(){static const char *text[]={
    "OBS changed while this editor was open. Close and reopen the editor before saving. Your pending edits have not been applied.",
    "OBS wurde geändert, während dieser Editor geöffnet war. Schließen und öffnen Sie den Editor erneut. Ihre ausstehenden Änderungen wurden nicht angewendet.",
    "Пока редактор был открыт, состояние OBS изменилось. Закройте редактор и откройте его снова. Ваши несохранённые изменения не применены.",
    "Поки редактор був відкритий, стан OBS змінився. Закрийте редактор і відкрийте його знову. Ваші незбережені зміни не застосовано.",
    "OBS a changé pendant que cet éditeur était ouvert. Fermez puis rouvrez l’éditeur avant d’enregistrer. Vos modifications en attente n’ont pas été appliquées.",
    "OBS ha cambiado mientras este editor estaba abierto. Ciérrelo y vuelva a abrirlo antes de guardar. No se han aplicado los cambios pendientes."};return QString::fromUtf8(text[LanguageIndex()]);}
inline QString FitChanged(){static const char *text[]={
    "The scene changed during the check. No automatic restoration or centering was performed. Review the current scene before using OBS Undo.",
    "Die Szene wurde während der Prüfung geändert. Es wurde nichts automatisch wiederhergestellt oder zentriert. Prüfen Sie die Szene, bevor Sie OBS Rückgängig verwenden.",
    "Во время проверки сцена изменилась. Автоматическое восстановление и центрирование не выполнены. Проверьте сцену, прежде чем использовать отмену OBS.",
    "Під час перевірки сцена змінилася. Автоматичне відновлення й центрування не виконано. Перевірте сцену, перш ніж використовувати скасування OBS.",
    "La scène a changé pendant la vérification. Aucune restauration ni aucun centrage automatique n’a été effectué. Vérifiez la scène avant d’utiliser Annuler dans OBS.",
    "La escena cambió durante la comprobación. No se restauró ni centró automáticamente. Revise la escena antes de usar Deshacer en OBS."};return QString::fromUtf8(text[LanguageIndex()]);}
inline QString PreviewFit(){static const char *text[]={
    "The source was fitted in Preview. Online quality checking is unavailable in Studio Mode because it captures Program. Use OBS Undo to reverse the fit.",
    "Die Quelle wurde in der Vorschau angepasst. Im Studiomodus ist die Online-Qualitätsprüfung nicht verfügbar, da sie die Programmausgabe erfasst. OBS Rückgängig nimmt die Anpassung zurück.",
    "Источник вписан в предпросмотр. Онлайн-проверка качества недоступна в студийном режиме: она захватывает программный выход. Отмена OBS вернёт прежнее положение.",
    "Джерело вписано в попередньому перегляді. Онлайн-перевірка якості недоступна в студійному режимі: вона захоплює програмний вихід. Скасування OBS поверне попередній стан.",
    "La source a été ajustée dans l’aperçu. La vérification en ligne n’est pas disponible en mode Studio car elle capture la sortie Programme. Annuler dans OBS rétablit l’état précédent.",
    "La fuente se ajustó en Vista previa. La comprobación en línea no está disponible en Modo Estudio porque captura Programa. Use Deshacer en OBS para revertir el ajuste."};return QString::fromUtf8(text[LanguageIndex()]);}
}
