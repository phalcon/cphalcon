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

use Phalcon\Forms\Form;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Forms\SetActionForm;

final class GetSetActionTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-11
     */
    public function testFormsFormGetSetAction(): void
    {
        $form = new Form();

        // empty action
        $this->assertSame(
            '',
            $form->getAction()
        );

        // set an action
        $form->setAction('/some-url');

        $this->assertSame(
            '/some-url',
            $form->getAction()
        );

        // clean action
        $form->setAction('');

        $this->assertSame(
            '',
            $form->getAction()
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-11
     */
    public function testFormsFormGetSetActionInitialize(): void
    {
        $form = new SetActionForm();

        $this->assertSame(
            '/users/login',
            $form->getAction()
        );
    }
}
