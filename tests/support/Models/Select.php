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

namespace Phalcon\Tests\Support\Models;

use Phalcon\Mvc\Model;

/**
 * Class Select
 */
class Select extends Model
{
    public $sel_id;
    public $sel_name;
    public $sel_text;

    public function getId()
    {
        return $this->sel_id;
    }

    public function getName()
    {
        return $this->sel_name;
    }

    public function getText()
    {
        return $this->sel_text;
    }

    public function initialize(): void
    {
        $this->setSource('ph_select');
    }

    public function setId($id)
    {
        $this->sel_id = $id;
    }

    public function setName($name)
    {
        $this->sel_name = $name;
    }

    public function setText($text)
    {
        $this->sel_text = $text;
    }
}
