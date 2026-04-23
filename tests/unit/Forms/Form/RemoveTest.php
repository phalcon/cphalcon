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

use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Tests\AbstractUnitTestCase;

final class RemoveTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testFormsFormRemoveFound(): void
    {
        $form = new Form();
        $form->add(new Text('name'));
        $form->add(new Text('email'));

        $actual = $form->remove('name');
        $this->assertTrue($actual);

        $actual = $form->has('name');
        $this->assertFalse($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testFormsFormRemoveNotFound(): void
    {
        $form = new Form();
        $form->add(new Text('name'));

        $actual = $form->remove('nonexistent');
        $this->assertFalse($actual);
    }
}
