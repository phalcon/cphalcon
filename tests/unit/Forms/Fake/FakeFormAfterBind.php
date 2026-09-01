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

class FakeFormAfterBind extends Form
{
    public bool $afterBindCalled = false;

    public function afterBind(?object $entity): void
    {
        $this->afterBindCalled = true;
    }
}
