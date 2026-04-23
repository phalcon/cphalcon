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

namespace Phalcon\Tests\Unit\Mvc\Micro;

use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Model\Binder;
use Phalcon\Mvc\Model\BinderInterface;
use Phalcon\Tests\AbstractUnitTestCase;

class SetModelBinderTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcMicroSetModelBinder(): void
    {
        $micro       = new Micro();
        $modelBinder = new Binder();
        $micro->setModelBinder($modelBinder);
        $this->assertInstanceOf(BinderInterface::class, $micro->getModelBinder());
    }
}
