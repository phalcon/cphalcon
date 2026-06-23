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

namespace Phalcon\Tests\Unit\Forms\Form;

use Phalcon\Di\FactoryDefault;
use Phalcon\Forms\Form;
use Phalcon\Tests\AbstractUnitTestCase;

final class UnderscoreGetTest extends AbstractUnitTestCase
{
    /**
     * The form inherits the injection-aware magic getter, resolving service
     * names through the container.
     *
     * Tests Phalcon\Forms\Form :: __get()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testFormsFormUnderscoreGet(): void
    {
        $container = new FactoryDefault();
        $form      = new Form();
        $form->setDI($container);

        // The special "di" property returns the container itself.
        $this->assertSame($container, $form->di);

        // A registered service is resolved through the container.
        $this->assertSame($container->getShared('escaper'), $form->escaper);

        // An unknown property triggers a notice and yields null.
        $this->assertNull(@$form->undefinedProperty);
    }
}
