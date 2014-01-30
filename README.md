UV-3R Fox
=========

This firmware (based on the UV3RMod that this project forks) turns the UV-3R into a fox.

By default, this firmware will transmit K2GXT (the Rochester Institute of Technology Amateur Radio Club callsign) every ~30 seconds on 146.565 MHz.  If you choose to use this firmware for your own purposes, you *MUST CHANGE THE CALLSIGN TO YOUR OWN*!!! You can do this in firmware/main.c line 78, you also have to change the second argument to the length of your callsign.

The UV button will turn the radio on/off.
The VOL button will toggle transmitting.
The MENU button will change the output power.  The ranges are from ~100mW to ~3W.

This firmware is experimental and is to be run at YOUR OWN RISK.


If you have any questions you can contact me at mjs7769@rit.edu.







Below is the original README file for the UV3RMod Repo.


UV3RMod
=======

This file is part of the uv3r firmware/programmer
More info at www.liorelazary.com

Created by Lior Elazary (KK6BWA) Copyright (C) 2013 <lior at elazary dot com> 

This program is free software; you can redistribute it and/or modify 
it under the terms of the GNU General Public License as published by 
the Free Software Foundation; either version 2 of the License, or 
(at your option) any later version. 

This program is distributed in the hope that it will be useful, 
but WITHOUT ANY WARRANTY; without even the implied warranty of 
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
GNU General Public License for more details. 

You should have received a copy of the GNU General Public License 
along with this program; if not, write to the Free Software 
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA 



Firmware and programmer to re-flash the UV3R radio

the firmwere directory is the uv3r firmwere which is work in progress

the programmer directory is an arduino code used to flash the radio

