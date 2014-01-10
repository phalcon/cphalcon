
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  |          Vladimir Kolesnikov <vladimir@free-sevastopol.com>            |
  +------------------------------------------------------------------------+
*/

#include "image/exception.h"
#include "image/../exception.h"
#include "kernel/main.h"

/**
 * Phalcon\Image\Exception
 *
 * Exceptions thrown in Phalcon\Image will use this class
 *
 */
zend_class_entry *phalcon_image_exception_ce;

/**
 * Phalcon\Image\Exception initializer
 */
PHALCON_INIT_CLASS(Phalcon_Image_Exception){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Image, Exception, image_exception, phalcon_exception_ce, NULL, 0);

	return SUCCESS;
}
