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
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;

final class LabelTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testFormsFormLabel(): void
    {
        $form = new Form();
        $form->setTagFactory(new TagFactory(new Escaper()));

        $element = new Text('email');
        $element->setLabel('Email address');

        $form->add($element);

        $this->assertStringContainsString('Email address', $form->label('email'));
    }
}
