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
use Phalcon\Tests\Unit\Forms\Fake\FakeFormCustomValue;

/**
 * Class GetValueTest extends AbstractUnitTestCase
 */
final class GetValueTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testFormsFormGetValueForbiddenNameReturnsNull(): void
    {
        $form = new Form();
        $form->add(new Text('action'));

        $actual = $form->getValue('action');
        $this->assertNull($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testFormsFormGetValueCustomValueMethod(): void
    {
        $form = new FakeFormCustomValue();
        $form->add(new Text('username'));

        $actual = $form->getValue('username');
        $this->assertSame('custom-username', $actual);
    }
}
