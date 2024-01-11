<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;

/**
 * Class Setters
 */
class Setters extends Model
{
    protected $id;
    protected $column1;
    protected $column2;
    protected $column3;

    public function initialize()
    {
        $this->setSource('co_setters');
        $this->keepSnapshots(true);
        $this->useDynamicUpdate(true);
    }

    public function setColumn1($column1): self
    {
        $this->column1 = $column1;

        return $this;
    }

    public function setColumn2($column2): self
    {
        $this->column2 = $column2;

        return $this;
    }

    public function setColumn3($column3): self
    {
        $this->column3 = $column3;

        return $this;
    }

    public function getColumn1(): string
    {
        return $this->column1;
    }

    public function getColumn2(): string
    {
        return $this->column2;
    }

    public function getColumn3(): string
    {
        return $this->column3;
    }
}
