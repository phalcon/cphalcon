<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models\AlbumORama;

use Phalcon\Mvc\Model;

class Albums extends Model
{
    public function initialize()
    {
        $this->belongsTo(
            'artists_id',
            Artists::class,
            'id',
            [
                'alias' => 'artist',
            ]
        );

        $this->hasMany(
            'id',
            Songs::class,
            'albums_id',
            [
                'alias' => 'songs',
            ]
        );

        $this->hasMany(
            [
                'id',
                'name',
            ],
            Songs::class,
            [
                'albums_id',
                'name',
            ],
            [
                'alias' => 'singles',
            ]
        );
    }
}
