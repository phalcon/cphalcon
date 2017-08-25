<?php

namespace Phalcon\Test\ModelRepositories\Snapshot;

use Phalcon\Mvc\Model\Repository;
use Phalcon\Test\Models\Snapshot\Robots;
use Phalcon\Test\Models\Snapshot\Parts;

/**
 * \Phalcon\Test\ModelRepositories\Snapshot\RobotsPartsRepository
 *
 * @copyright 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\ModelRepositories\Snapshot
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class RobotsPartsRepository extends Repository
{
    public function initialize()
    {
        $this->belongsTo(
            "robots_id",
            Robots::class,
            "id"
        );

        $this->belongsTo(
            "parts_id",
            Parts::class,
            "id"
        );
    }
}
