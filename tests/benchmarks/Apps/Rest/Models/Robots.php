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

namespace Phalcon\Tests\Benchmarks\Apps\Rest\Models;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Mvc\Model;

final class Robots extends Model
{
    public ?int $id = null;

    public string $name = '';

    public string $type = '';

    public int $year = 0;

    public function initialize(): void
    {
        $this->setSource('robots');
    }

    public function validation(): bool
    {
        $validation = new Validation();
        $validation->add('name', new PresenceOf());

        return $this->validate($validation);
    }
}
