
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
<<<<<<< HEAD:ext/kernel/extended/array.c
  | Copyright (c) 2011-2015 Zephir Team (http://www.zephir-lang.com)       |
=======
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
>>>>>>> master:ext/image.h
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@zephir-lang.com so we can send you a copy immediately.      |
  +------------------------------------------------------------------------+
<<<<<<< HEAD:ext/kernel/extended/array.c
  | Authors: Andres Gutierrez <andres@zephir-lang.com>                     |
  |          Eduar Carvajal <eduar@zephir-lang.com>                        |
  +------------------------------------------------------------------------+
*/
=======
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  |          Vladimir Kolesnikov <vladimir@free-sevastopol.com>            |
  +------------------------------------------------------------------------+
*/

#ifndef PHALCON_IMAGE_H
#define PHALCON_IMAGE_H

#include "php_phalcon.h"

/* Resizing constraints */
#define PHALCON_IMAGE_NONE           1
#define PHALCON_IMAGE_WIDTH          2
#define PHALCON_IMAGE_HEIGHT         3
#define PHALCON_IMAGE_AUTO           4
#define PHALCON_IMAGE_INVERSE        5
#define PHALCON_IMAGE_PRECISE        6
#define PHALCON_IMAGE_TENSILE        7

/* Flipping directions */
#define PHALCON_IMAGE_HORIZONTAL    11
#define PHALCON_IMAGE_VERTICAL      12

/* Driver: GD, ImageMagick, etc */
#define PHALCON_IMAGE_GD            21
#define PHALCON_IMAGE_IMAGICK       22


extern zend_class_entry *phalcon_image_ce;

PHALCON_INIT_CLASS(Phalcon_Image);

#endif /* PHALCON_IMAGE_H */
>>>>>>> master:ext/image.h
