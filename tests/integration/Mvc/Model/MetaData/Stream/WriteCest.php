<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model\MetaData\Stream;

use function file_exists;
use function file_put_contents;
use IntegrationTester;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\MetaData\Stream;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Robots;
use function unlink;

/**
 * Class WriteCest
 */
class WriteCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\Model\MetaData\Stream :: write()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelMetadataStreamWrite(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\MetaData\Stream - write()');
        $I->skipTest('Need implementation');
    }

    /**
     * Tests Phalcon\Mvc\Model\MetaData\Stream :: write() - exception
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelMetadataStreamWriteException(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\MetaData\Stream - write()');
        $directory = outputDir('tests/');
        $fileName  = $directory . 'metadata';
        $this->setNewFactoryDefault();
        $this->setDiMysql();
        $this->container->set(
            'modelsMetadata',
            function () use ($fileName) {
                return new Stream(['metaDataDir' => $fileName . '/']);
            }
        );
        $I->expectThrowable(
            new Exception('Meta-Data directory cannot be written'),
            function () use ($I, $fileName) {
                if (file_exists($fileName)) {
                    unlink($fileName);
                }
                $result = file_put_contents($fileName, '');
                $I->assertNotFalse($result);
                Robots::setup(
                    [
                        'exceptionOnFailedMetaDataSave' => true,
                    ]
                );
                Robots::findFirst(1);
            }
        );
        $I->expectThrowable(
            new \Exception('Meta-Data directory cannot be written', 1024),
            function () use ($I, $fileName) {
                if (file_exists($fileName)) {
                    unlink($fileName);
                }
                $result = file_put_contents($fileName, '');
                $I->assertNotFalse($result);
                Robots::setup(
                    [
                        'exceptionOnFailedMetaDataSave' => false,
                    ]
                );
                Robots::findFirst(1);
            }
        );
    }
}
