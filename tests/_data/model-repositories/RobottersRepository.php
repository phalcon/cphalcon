<?php

namespace Phalcon\Test\ModelRepositories;

use Phalcon\Mvc\Model\Repository;
use Phalcon\Test\Models\RobottersDeles;

/**
 * \Phalcon\Test\ModelRepositories\RobottersRepository
 *
 * @copyright 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\ModelRepositories
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class RobottersRepository extends Repository
{
    public function initialize()
    {
        $this->setSource("robots");

        $this->hasMany(
            "code",
            RobottersDeles::class,
            "robottersCode",
            [
                "foreignKey" => true,
            ]
        );
    }

    public function columnMap()
    {
        return [
            'id' => 'code',
            'name' => 'theName',
            'type' => 'theType',
            'year' => 'theYear',
            'datetime' => 'theDatetime',
            'deleted' => 'theDeleted',
            'text' => 'theText',
        ];
    }
}
