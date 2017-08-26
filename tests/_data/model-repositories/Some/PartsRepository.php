<?php

namespace Phalcon\Test\ModelRepositories\Some;

use Phalcon\Mvc\Model\Repository;
use Phalcon\Test\Models\RobotsParts;

/**
 * \Phalcon\Test\ModelRepositories\Some\PartsRepository
 *
 * @copyright 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\ModelRepositories\Some
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class PartsRepository extends Repository
{
    public function initialize()
    {
        $this->setSource("parts");

        $this->hasMany(
            "id",
            RobotsParts::class,
            "parts_id",
            [
                "foreignKey" => [
                    "message" => "Parts cannot be deleted because is referenced by a Robot",
                ]
            ]
        );
    }
}
