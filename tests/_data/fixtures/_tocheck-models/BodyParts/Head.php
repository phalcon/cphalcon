<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Models\BodyParts;

use Phalcon\Mvc\Model;

class Head extends Model
{
    public $id;

    public function initialize()
    {
        $this->setSource('issue12071_head');
    }
}
