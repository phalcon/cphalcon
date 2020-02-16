<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;

/**
 * Class RobotPart
 *
 * @property int    $robot_part_id;
 * @property string $robot_part_name;
 */
class RobotPart extends Model
{
    public $robot_part_id;
    public $robot_part_name;

    public function initialize()
    {
        $this->setSchema('public');
        $this->setSource('robot_part');
    }
}
