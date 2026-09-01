<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Support\Models\AlbumORama;

use Phalcon\Mvc\Model;

class Songs extends Model
{
    public function initialize()
    {
        $this->hasMany(
            'id',
            Albums::class,
            'albums_id',
            [
                'alias' => 'album',
            ]
        );
    }
}
