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

class Artists extends Model
{
    public function initialize()
    {
        $this->hasMany(
            'id',
            Albums::class,
            'artists_id',
            [
                'alias' => 'albums',
            ]
        );
    }
}
