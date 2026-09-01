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

namespace Phalcon\Tests\Unit\Forms\Form\Fake;

use Phalcon\Mvc\Model;

class FakeSelect extends Model
{
    public function getId(): mixed
    {
        return $this->sel_id;
    }

    public function getName(): mixed
    {
        return $this->sel_name;
    }

    public function getText(): mixed
    {
        return $this->sel_text;
    }
    public function initialize(): void
    {
        $this->setSource('ph_select');
    }

    public function setId(mixed $id): void
    {
        $this->sel_id = $id;
    }

    public function setName(mixed $name): void
    {
        $this->sel_name = $name;
    }

    public function setText(mixed $text): void
    {
        $this->sel_text = $text;
    }
}
