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

final class GetLabelTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testFormsFormGetLabel(): void
    {
        $form = new Form();

        $element = new Text('email');
        $element->setLabel('Email address');

        $form->add($element);

        $this->assertSame('Email address', $form->getLabel('email'));

        // Element without a label falls back to its name
        $unlabeled = new Text('username');
        $form->add($unlabeled);

        $this->assertSame('username', $form->getLabel('username'));
    }
}
