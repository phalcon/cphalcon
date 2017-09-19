<?php

namespace Phalcon\Test\Models\AlbumORama;

use Phalcon\Mvc\Model;

/**
 * \Phalcon\Test\Models\AlbumORama\Artists
 *
 * @property string $name
 *
 * @copyright 2011-2017 Phalcon Team
 * @link      https://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Models\AlbumORama\Albums
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Artists extends Model
{
    public function initialize()
    {
        $this->hasMany(
            'id',
            'AlbumORama:Albums',
            'artists_id',
            ['alias' => 'albums']
        );
    }
}
