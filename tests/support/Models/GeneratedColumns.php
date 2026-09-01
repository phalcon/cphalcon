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

namespace Phalcon\Tests\Support\Models;

use Phalcon\Mvc\Model;

class GeneratedColumns extends Model
{
    public $gen_id;
    public $gen_url;
    public $gen_url_hash;

    public function initialize()
    {
        $this->setSource('co_generated');
    }
}
