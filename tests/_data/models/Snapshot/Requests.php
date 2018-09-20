<?php

namespace Phalcon\Test\Models\Snapshot;

use Phalcon\Mvc\Model;

/**
 * Phalcon\Test\Models\Snapshot\Requests
 *
 * @package Phalcon\Test\Models\Snapshot
 *
 * @property string $method
 * @property string $uri
 * @property int $count
 *
 * @method static Requests findFirst($parameters = null)
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
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
