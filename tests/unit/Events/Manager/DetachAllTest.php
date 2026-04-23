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

namespace Phalcon\Tests\Unit\Events\Manager;

use Phalcon\Events\Manager;
use Phalcon\Tests\AbstractUnitTestCase;

final class DetachAllTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEventsManagerDetachAll(): void
    {
        $eventType = 'some:upload';
        $manager   = new Manager();
        $manager->attach(
            $eventType,
            function () {
                return true;
            }
        );

        $actual = $manager->getListeners($eventType);
        $this->assertCount(1, $actual);

        $manager->detachAll();

        $actual = $manager->hasListeners($eventType);
        $this->assertFalse($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEventsManagerDetachAllWithType(): void
    {
        $uploadType = 'some:upload';
        $downloadType = 'some:download';
        $manager = new Manager();
        $manager->attach(
            $uploadType,
            function () {
                return true;
            }
        );

        $manager->attach(
            $downloadType,
            function () {
                return true;
            }
        );

        $actual = $manager->hasListeners($uploadType);
        $this->assertTrue($actual);
        $actual = $manager->hasListeners($downloadType);
        $this->assertTrue($actual);

        $manager->detachAll($uploadType);

        $actual = $manager->hasListeners($uploadType);
        $this->assertFalse($actual);
        $actual = $manager->hasListeners($downloadType);
        $this->assertTrue($actual);
    }
}
