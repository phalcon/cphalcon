<?php
/**
 * Parts.php
 * Parts
 *
 * Parts model
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2015 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Eduar Carvajal <eduar@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@niden.net>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

class Parts extends \Phalcon\Mvc\Model
{

	public function initialize()
	{
		$this->hasMany(
            'id',
            'RobotsParts',
            'parts_id',
            array(
                'foreignKey' => array(
                    'message' => 'Parts cannot be deleted because is referenced by a Robot'
                )
		    )
        );
	}

}
