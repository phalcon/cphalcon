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

namespace Phalcon\Tests\Unit\Forms\Fake;

use Phalcon\Forms\Form;

final class FakeCountingFormFactory
{
    public int $callCount = 0;

    public function __invoke(?object $entity): Form
    {
        $this->callCount++;

        return new Form($entity);
    }
}
