<?php

namespace Phalcon\Test\Models\AlbumORama;

use Phalcon\Mvc\Model;

/**
 * \Phalcon\Test\Models\AlbumORama\Albums
 *
 * @property Artists $artist
 * @property Artists $Artist
 *
 * @method static Albums findFirst($parameters = null)
 * @method static Albums[] find($parameters = null)
 *
 * @copyright 2011-2017 Phalcon Team
 * @link      https://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Models\AlbumORama
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Albums extends Model
{
    public function initialize()
    {
        $this->belongsTo(
            'artists_id',
            'AlbumORama:Artists',
            'id',
            ['alias' => 'artist']
        );
    }
}
