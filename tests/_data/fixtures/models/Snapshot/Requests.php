<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models\Snapshot;

use Phalcon\Mvc\Model;

/**
 * @property string $method
 * @property string $uri
 * @property int    $count
 *
 * @method static Requests findFirst($parameters = null)
 */
class Requests extends Model
{
    public function initialize()
    {
        $this->setSource('identityless_requests');
        $this->keepSnapshots(true);
    }

    public function columnMap()
    {
        return [
            'method'        => 'method',
            'requested_uri' => 'uri',
            'request_count' => 'count',
        ];
    }
}
