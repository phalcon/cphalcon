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

/**
 * Class OnlyIdentity
 *
 * Model bound to a table that has only an auto-increment primary key column.
 *
 * @property int $oid_id
 */
class OnlyIdentity extends Model
{
    public $oid_id;

    public function initialize()
    {
        $this->setSource('co_only_identity');
    }
}
