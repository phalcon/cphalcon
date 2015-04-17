<?php
/**
 * RobotsParts.php
 * RobotsParts
 *
 * RobotsParts model
 *
 * Phalcon Framework
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

class RobotsParts extends \Phalcon\Mvc\Model
{

	public function initialize()
	{
		$this->belongsTo(
            'parts_id',
            'Parts',
            'id',
            array('foreignKey' => true)
        );

		$this->belongsTo(
            'robots_id',
            'Robots',
            'id',
            array(
			    'foreignKey' => array(
				    'message' => 'The robot code does not exist'
			    )
		    )
        );
	}

}
