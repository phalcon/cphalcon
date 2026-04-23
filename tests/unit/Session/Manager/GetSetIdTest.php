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

namespace Phalcon\Tests\Unit\Session\Manager;

use Phalcon\Session\Exception;
use Phalcon\Session\Manager;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

use function uniqid;

final class GetSetIdTest extends AbstractUnitTestCase
{
    use DiTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSessionManagerGetSetId(): void
    {
        $manager = new Manager();
        $files   = $this->newService('sessionStream');
        $manager->setAdapter($files);

        $actual = $manager->getId();
        $this->assertEquals('', $actual);

        $id = uniqid();
        $manager->setId($id);

        $actual = $manager->getId();
        $this->assertEquals($id, $actual);

        $manager->destroy();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSessionManagerSetIdException(): void
    {
        $manager = new Manager();
        $files   = $this->newService('sessionStream');
        $manager->setAdapter($files);

        try {
            $manager->start();

            $id = uniqid();
            $manager->setId($id);
            $valid   = false;
        } catch (Exception $ex) {
            $manager->destroy();
            $valid    = true;
            $expected = 'The session has already been started. ' .
                'To change the id, use regenerateId()';
            $actual   = $ex->getMessage();
            $this->assertEquals($expected, $actual);
        }

        $this->assertTrue($valid);
    }
}
