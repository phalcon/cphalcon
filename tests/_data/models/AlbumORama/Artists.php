<?php

namespace Phalcon\Test\Models\AlbumORama;

use Phalcon\Mvc\Model;

/**
 * \Phalcon\Test\Models\AlbumORama\Artists.php
 * Artists model class
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Models\AlbumORama\Albums
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Artists extends Model
{
	public function initialize()
	{
		$this->hasMany('id', 'AlbumORama:Albums', 'artists_id', array(
			'alias' => 'albums'
		));
	}
}
