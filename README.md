NOTICE
======
This is a fork of the famous setBfree-organ-simulation. This software should be
used as native LV2-plugin inside MOD-UI. Every external MIDI-support and internal UI-support is currently dropped or will be dropped in future releases.

setBfreak
=========

A DSP Tonewheel Organ emulator - based on setBFree

setBfreak is a MIDI-controlled, software synthesizer designed to imitate the
sound and properties of the electromechanical organs and sound modification
devices that brought world-wide fame to the names and products of Laurens
Hammond and Don Leslie.

*   http://setbfree.org
*   https://github.com/pantherb/setBfree

Because there were some changes in the code which won't get into the main code
of setbfree, I decided to rename the project. I made these changes for better
integration into MOD-UI - especially for linking parameters to LV2 controllers
(instead of MIDI controllers which cannot be changed as flexible as MIDI-learn
in MOD-UI)

Internal Signal Flow
--------------------

	     +--------+    /-----------\    /--------\
	     |        |    |           |    |        |
	MIDI | Synth- |    |  Preamp/  |    |        |
	--=->|        +--->|           +--->| Reverb +--\
	     | Engine |    | Overdrive |    |        |  |
	     |        |    |           |    |        |  |
	     +--------+    \-----------/    \--------/  |
	                                                |
	  /---------------------------------------------/
	  |
	  |  /--------\ Horn L/R  /-----------\
	  |  |        +---------->|  Cabinet  +-----*--> Audio-Out Left
	  |  |        +---------->| Emulation +--\  |
	  \->| Leslie |           \-----------/  |  |
	     |        +--------------------------|--/
	     |        +--------------------------*-----> Audio-Out Right
	     \--------/ Drum L/R

Render diagram with http://ditaa.org/
A pre-rendered image is available in the doc/ folder.

Each of the stages is a seperate LV2 plugin.

The Vibrato and Chorus effects are built into the synth-engine itself, as are
key-click and percussion modes. These features are linked to the tone
generation itself and can not be broken-out to standalone effects.

Thanks
------
Thanks for Robin Gareus and ...

Many thanks to all who contributed ideas, bug-reports, patches and feedback. In
Particular (in alphabetical order): Dominique Michel, Fons Adriaensen, Jean-Luc
Nest, Jeremy Jongepier, Julien Claasen and Ken Restivo.
