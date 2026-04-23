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

use Phalcon\Html\Attributes;
use Phalcon\Forms\Form;
use Phalcon\Tests\AbstractUnitTestCase;

final class SetAttributesTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testFormsFormSetAttributes(): void
    {
        $form       = new Form();
        $attributes = new Attributes(['action' => '/submit', 'method' => 'post']);

        $actual = $form->setAttributes($attributes);
        $this->assertInstanceOf(Form::class, $actual);

        $this->assertSame($attributes, $form->getAttributes());
    }
}
