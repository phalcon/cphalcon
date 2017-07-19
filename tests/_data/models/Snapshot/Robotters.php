<?php

namespace Phalcon\Test\Models\Snapshot;

use Phalcon\Mvc\Model;
use Phalcon\Test\Models\RobottersDeles;

/**
 * \Phalcon\Test\Models\Snapshot\Robotters
 *
 * @copyright 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Models\Snapshot
 *
 * @property int $code
 * @property sting $theName
 * @property string $theType
 * @property int $theYear
 * @property string $theDatetime
 * @property string $theDeleted
 * @property string $theText
 *
 * @method static Robotters findFirst($parameters = null)
 * @method static Robotters[] find($parameters = null)
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Robotters extends Model
{
    public function getSource()
    {
        return 'robots';
    }

    public function columnMap()
    {
        return [
            'id'       => 'code',
            'name'     => 'theName',
            'type'     => 'theType',
            'year'     => 'theYear',
            'datetime' => 'theDatetime',
            'deleted'  => 'theDeleted',
            'text'     => 'theText',
        ];
    }

    public function initialize()
    {
        $this->hasMany('code', RobottersDeles::class, 'robottersCode');

        $this->keepSnapshots(true);
    }
}
