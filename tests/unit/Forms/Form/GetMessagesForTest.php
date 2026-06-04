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
use Phalcon\Messages\Messages;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetMessagesForTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testFormsFormGetMessagesFor(): void
    {
        $form = new Form();
        $form->add(new Text('email'));

        // No validation run yet → empty Messages
        $messages = $form->getMessagesFor('email');
        $this->assertInstanceOf(Messages::class, $messages);
        $this->assertCount(0, $messages);

        // Unknown element → empty Messages, no exception
        $messages = $form->getMessagesFor('not_added');
        $this->assertInstanceOf(Messages::class, $messages);
        $this->assertCount(0, $messages);
    }
}
