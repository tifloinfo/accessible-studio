# Sound features: questions and answers

Use this reference with the [user guide](README.en-US.html). The audio tools need no API key.

## Which tool should I use?

The **Accessible Volume Console** adjusts source volume, monitoring, and program output. **Audible Meter** gives warnings and spoken level measurements. **Sound Doctor** runs a separate measurement session and suggests optional filters. Audible Meter and Sound Doctor cannot run together.

All work locally with fixed-size statistics in memory. They do not record or transmit audio or save measurement histories and reports. Settings and pre-fader opt-outs are retained.

## What do the numbers mean?

The console's dB value is fader gain: 0 dB leaves the level unchanged; negative values reduce it. It is not measured loudness.

Peak readings describe short signal peaks. RMS describes signal energy and is used for typical levels and dynamic variation. Meter readings use dBFS; values nearer 0 dBFS are higher. Pre-fader means before the OBS volume control; post-fader means after it. Lowering that control cannot repair distortion already present in the input.

## Why does JAWS read the previous volume?

Its arrow-key handling can speak the old slider number before the plugin announces the correct result with “dB.” This can falsely suggest a reversed adjustment. Insert+3 followed by the arrow removed the stale announcement in the reported test. The JAWS issue is being referred to Vispero; explicit final-value speech remains supported for JAWS and NVDA.

## How are tones triggered?

Automatic output warnings use accumulated exposure above a boundary. Defaults are 1.5 seconds and OBS's red boundary: −9 dBFS with sample peak or −2 dBFS with true peak. Dips shorter than one second do not fully reset exposure; one second below the boundary rearms it.

Console tones, available while Audible Meter is active, respond immediately to the focused source. Yellow produces a middle tone; red a high tone. Sample-peak yellow/red boundaries are −20/−9 dBFS; true-peak boundaries are −13/−2 dBFS. Green, no signal, unavailable sources, and focus outside source controls are silent.

A low tone guides adjustment of an eligible live input that remains red before the fader. It starts after you agree to adjust the input. Media Source and VLC Video Source do not produce pre-fader warnings.

## Can I silence warnings but keep measurements?

Yes. I toggles automatic input and output warnings while Audible Meter is active. Re-enabling starts fresh exposure timing. Console tones and H/J/K/L remain available. These letters are never intercepted in editable controls.

H gives the selected source's current output level and zone; J identifies the loudest source now. K gives the selected source's typical active RMS level for the session; L identifies the source with the highest typical active level. Selection follows the source most recently focused in the console.

## How does requested correction work?

Press Shift+I during an output warning. For each responsible source, the target is the warning level minus the safety margin. Reduction uses the incident's highest observed peak, rounds upward to 0.5 dB, and is capped at the configured maximum. It never raises gain or adjusts a source solely for a pre-fader warning.

Defaults are a 3 dB margin and 12 dB maximum reduction. This protects peaks; it does not balance speech, music, and effects for you.

Ctrl+Shift+I restores the last correction only on faders still matching the corrected values. Starting or stopping the meter, changing scene collection, or saving meter settings clears this one-step restoration record.

## Why does input guidance pause other warnings?

Potential distortion before the fader takes priority. The initial dialog is silent. Yes starts guidance; No or Escape saves an opt-out for that unchanged source. A sustained healthy active signal resolves the incident. Changed identity or settings cause a fresh evaluation.

Silence is not success. No-signal announcements occur after 2 and 12 seconds, followed by a question after 22 seconds. Continuing waits for signal without repeating that silence sequence. Acknowledge the safe-level message before other warnings resume.

While the console is open, output timing pauses and input problems queue. Healthy active audio clears a queued problem; silence keeps it queued. Closing the console presents any still-relevant input problem first.

## What can I configure for Audible Meter?

Open **Audio Tools > Advanced Sound Settings > Audible Meter**:

- Output-warning level: −30 to 0 dBFS; default follows OBS peak mode.
- Exposure time: 0.1–30 seconds; default 1.5 seconds.
- Peak safety margin: 0–12 dB; default 3 dB.
- Maximum reduction: 0.5–30 dB; default 12 dB.
- Pre-fader stop list: remove opt-outs to check those inputs again.

These settings do not change console zones, H/J/K/L readings, or the input red boundary. There is one windowless meter mode. Apply saves; OK saves and closes; Cancel discards edits since the last Apply.

## How long does Sound Doctor need?

At least 120 seconds, with at least 45 seconds of active audio per source for processing recommendations. Both durations are fixed. Measurement can continue during streaming or recording; results wait until both stop. Use representative speech and sound. The tool measures levels and cannot reliably distinguish speech from music.

## When is compression recommended?

The source must be a likely live input, have enough active audio, remain unchanged, and have no existing compressor or limiter, including disabled ones. Dynamic spread must reach the configured minimum, 8 dB by default.

Spread is the difference between median active RMS and the 95th-percentile RMS. RMS is corrected for OBS fader gain. A new compressor follows existing processing and precedes a newly selected limiter.

Threshold is median plus 5 dB, rounded and limited to −24 through −10 dB. Attack is 6 ms, release 100 ms, and output gain 0 dB. Ratio is 2:1 below 10 dB spread, 2.5:1 from 10 to below 14 dB, and the configured maximum from 14 dB. Leave music compression unselected unless you want the effect.

## When is a limiter recommended?

By default, for sufficiently active likely live inputs that remain unchanged and have no limiter. Clipping need not have occurred: protection is preventive. A new limiter is last, with a default −3 dBFS ceiling and 60 ms release. It cannot repair earlier distortion or guarantee that the combined mix will not overload.

Scope can include all active sources, though mastered media may not need another limiter. Compressor and limiter recommendations are independent. The report also explains existing processing, a limiter not placed last, repeated near-clipping input peaks, and insufficient or stale evidence.

## Which Sound Doctor settings are available?

- Minimum dynamic spread: 6–15 dB; default 8 dB.
- Maximum compressor ratio: 2.5:1, 3:1, or 3.5:1; default 3:1. Lower ratios may still be recommended.
- Limiter scope: likely live inputs or all active sources.
- Limiter ceiling: −12 to −1 dBFS; default −3 dBFS.

## Can it change my setup without approval?

No. All recommendation checkboxes start unchecked. Finish applies selected items only after rechecking sources, volume, and filters. Changed sources are skipped. Escape closes without applying. Added Sound Doctor filters support OBS Undo and Redo.

Press Ctrl+Shift+D again to interrupt measurement and confirm discarding the session. No or Escape continues. The remember-choice option can disable that confirmation.
