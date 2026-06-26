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

namespace Phalcon\Tests\Database\Mvc\Model\Query\Status;

use Phalcon\Messages\Message;
use Phalcon\Messages\MessageInterface;
use Phalcon\Mvc\Model\Query\Status;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class GetMessagesTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * getMessages() returns the messages of the related model, or an empty
     * array when no model is set.
     *
     * Tests Phalcon\Mvc\Model\Query\Status :: getMessages()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelQueryStatusGetMessages(): void
    {
        $this->assertSame([], (new Status(true))->getMessages());

        $model = new Invoices();
        $model->appendMessage(new Message('Some error'));

        $messages = (new Status(false, $model))->getMessages();

        $this->assertCount(1, $messages);
        $this->assertInstanceOf(MessageInterface::class, $messages[0]);
    }
}
