<?php

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Resultset\Simple;

/**
 * \Phalcon\Test\Models\Robots
 *
 * @method static int countByType(string $type)
 * @method static Simple findByType(string $type)
 * @method static Robots findFirstById(string|int $id)
 *
 * @copyright 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Models
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Robots extends Model
{
    public function initialize()
    {
        $this->keepSnapshots(true);

        $this->hasMany(
            'id',
            RobotsParts::class,
            'robots_id',
            [
                'foreignKey' => true,
                'reusable' => false,
                'alias' => 'parts'
            ]
        );
    }
}
