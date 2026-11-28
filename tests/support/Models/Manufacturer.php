<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Support\Models;

use Phalcon\Mvc\Model;

/**
 * Class Manufacturer
 *
 * @property int    $id;
 * @property string $name;
 * @property string $country;
 * @property int    $founded_year;
 */
class Manufacturer extends Model
{
    public ?int $id;

    public string $name;

    public string $country = 'UK';

    public ?int $founded_year;

    public function initialize()
    {
        $this->setSource('co_manufacturers');
    }

    public function columnMap()
    {
        return [
            'id'           => 'id',
            'name'         => 'name',
            'country'      => 'country',
            'founded_year' => 'founded_year',
        ];
    }
}
