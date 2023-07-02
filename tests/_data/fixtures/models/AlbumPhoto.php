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

namespace Phalcon\Tests\Fixtures\models;

use Phalcon\Mvc\Model;

class AlbumPhoto extends Model
{
    public function initialize()
    {
        $this->setSource('album_photo');
    }
}
