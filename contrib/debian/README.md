
Debian
====================
This directory contains files used to package zeurod/zeuro-qt
for Debian-based Linux systems. If you compile zeurod/zeuro-qt yourself, there are some useful files here.

## zeuro: URI support ##


zeuro-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install zeuro-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your zeuro-qt binary to `/usr/bin`
and the `../../share/pixmaps/zeuro128.png` to `/usr/share/pixmaps`

zeuro-qt.protocol (KDE)

