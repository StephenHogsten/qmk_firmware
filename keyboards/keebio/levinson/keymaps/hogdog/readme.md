# TODO
* [X] add "ls -ahl" button
* [X] tweak tap / hold settings
  * turned on permissive hold and ignore mod tap interrupt (if you let go of tap modifier before you let go of next key it does both as taps)
* [ ] add / install underglow
* [ ] add / install backlight (this require desoldering for the resisters to fit)
* [ ] add button for clipit shortcut?
* [X] decide on whether to have two shift keys or a shift and a control (I think control is probably better on the left)
* [X] should the layer keys be tap layers?
  * maybe make the four taps: del - space -- enter - backspace?
    * maybe tab instead of del? - yes, this is a good idea
      * then make tap layers for _SYM and _ALT (maybe del on right, not sure for right)
      * also we shouldn't need bksp for _NAV enter anymore
    * maybe on alternate layer it could have alt tab controls on the thumbs?
    * but if I get used to the thumbs for shift + control maybe I should just keep them the same on all layers
  * or use: enter space -- backspace del?
  * could alt tab be moved to the nav layer? - right now it seems like too many buttons
  * now that this is true, we could definitely make _ADJUST something else for home row
    * maybe put brackets here instead? or other symbols?
* [X] use super alt tab code, but with alt tab and alt ` (https://docs.qmk.fm/#/feature_macros?id=super-alt↯tab)
  * the adjust layer + hold is annoying b/c if i hit alt before the second layer, it won't register as alt
* [ ] figure out how to remove those two dumb keys  (what is this talking about? dactyl?)
* [X] add brightness somewhere 
* [X] ~~add arrow function button? (maybe better as just a snippet - made one "anon")~~
* [X] super alt tab [ref](https://docs.qmk.fm/#/feature_macros?id=super-alt%e2%86%aftab)
* [X] add menu option somewhere (is it like right clicking on focused element?)
* [X] swap pgup and down (to match hjkl)
* [ ] it would be great it nav right thumb (enter) could be ctrl + enter, but it seems tough b/c of the caveat.  may be a hack available with leader key or something or custom code
* [X] add locking layers to adj layer (esp. for locking arrow keys)
  [ ] nav lock (the one that matters) is not consistent - if you want to lock layer A you need to use B to get to adjust (otherwise letting go of A will turn it back off). I think we could add better code to switch layers for adjust to keep this from happening
* [X] caps lock
* [ ] gaming / overwatch layout 
* [ ] flash both sides? It'd be nice to plug into whichever half is more convenient
* [ ] make the mouse movements easier to use somehow?

# Notes
* maybe it would be better to put control on the right?
  * then I could use shift on the number / symbol layer more easily
    * then i could reuse the second third layer for something else
  * arrow + shift is harder, arrow + control is easier
    * but honestly i still have the ctrl + shift key so it shouldn't matter
  * ctrl backspace is impossible (unless i reach w/ the pinkie or move backspace to tap)
  * may be easeir to think about the right hand as more of the "doer" so it does ctrl actions
  * if i mess up with backspace i get a space instead of an enter (I keep submitting things to console)
  * much easier to ctrl + page up / down
  * can't do ctrl + enter
    * could move this to nav layer once I'm more used to backspace tap?
  * harder to indent in vscode (ctrl + ])
* what would be the best things for tapping the layers?
  * what makes me leave home row the most right now?
    * alt tab / alt `
      * this could be on the up+down layer
    * anything with tab