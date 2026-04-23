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
use Phalcon\Messages\Messages;

class FakeFormAfterValidation extends Form
{
    public bool $afterCalled = false;

    public function afterValidation(Messages $messages): void
    {
        $this->afterCalled = true;
    }
}
