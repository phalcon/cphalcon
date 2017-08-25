<?php

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Test\ModelRepositories\RobotsRepository;

/**
 * \Phalcon\Test\Models\Robots
 *
 * @method static int countByType(string $type)
 * @method static Simple findByType(string $type)
 * @method static Robots findFirstById(string|int $id)
 *
 * @copyright 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Models
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Robots extends Model
{
    /**
     * @var bool
     */
    public $wasSetterUsed = false;

    /**
     * @var string
     */
    protected $name;

    public static function getRepositoryClass()
    {
        return RobotsRepository::class;
    }

    public function initialize()
    {
        $this->keepSnapshots(true);
    }

    public function setName($name)
    {
        $this->name = $name;
        $this->wasSetterUsed = true;

        return $this;
    }
}
