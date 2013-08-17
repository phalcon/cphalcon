/*
+------------------------------------------------------------------------+
| Phalcon Framework                                                      |
+------------------------------------------------------------------------+
| Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
+------------------------------------------------------------------------+
| This source file is subject to the New BSD License that is bundled     |
| with this package in the file docs/LICENSE.txt.                        |
|                                                                        |
| If you did not receive a copy of the license and are unable to         |
| obtain it through the world-wide-web, please send an email             |
| to license@phalconphp.com so we can send you a copy immediately.       |
+------------------------------------------------------------------------+
| Authors: Andres Gutierrez <andres@phalconphp.com>                      |
|          Eduar Carvajal <eduar@phalconphp.com>                         |
+------------------------------------------------------------------------+
*/
/*
* Memory Frames/Virtual Symbol Scopes
*------------------------------------
*
* Phalcon uses memory frames to track the variables used within a method
* in order to free them or reduce their reference counting accordingly before
* exit the method in execution.
*
* This adds a minimum overhead to execution but save us the work of
* free memory in each method.
*
* The whole memory frame is an open double-linked list which start is an
* allocated empty frame that points to the real first frame. The start
* memory frame is globally accesed using PHALCON_GLOBAL(start_frame)
*
* Not all methods must grown/restore the phalcon_memory_entry.
*/
