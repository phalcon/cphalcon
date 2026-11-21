<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Security;

use Phalcon\Encryption\Security;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use ReflectionMethod;

final class HashTest extends AbstractUnitTestCase
{
    /**
     * @return array<string, array{0: mixed}>
     */
    public static function getEmptyCostExamples(): array
    {
        return [
            'null'         => [null],
            'zero'         => [0],
            'zero string'  => ['0'],
            'false'        => [false],
            'empty string' => [''],
        ];
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17764
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-21
     */
    #[DataProvider('getEmptyCostExamples')]
    public function testEncryptionSecurityHashCostEmpty(mixed $cost): void
    {
        $security = new Security();

        $hash = $security->hash('secret', ['cost' => $cost]);

        $this->assertSame(10, $security->getHashInformation($hash)['options']['cost']);
        $this->assertTrue($security->checkHash('secret', $hash));
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17764
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-21
     */
    #[DataProvider('getEmptyCostExamples')]
    public function testEncryptionSecurityHashCostEmptyLegacy(mixed $cost): void
    {
        $security = new Security();
        $security->setDefaultHash(Security::CRYPT_BLOWFISH_A);

        $hash = $security->hash('secret', ['cost' => $cost]);

        $this->assertStringStartsWith('$2a$10$', $hash);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17764
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-21
     */
    #[DataProvider('getEmptyCostExamples')]
    public function testEncryptionSecurityHashCostEmptyWorkFactor(mixed $cost): void
    {
        $security = new Security();
        $security->setWorkFactor(12);

        $hash = $security->hash('secret', ['cost' => $cost]);

        $this->assertSame(12, $security->getHashInformation($hash)['options']['cost']);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17764
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-21
     */
    public function testEncryptionSecurityHashCostLimits(): void
    {
        $security = new Security();

        $hash = $security->hash('secret', ['cost' => 3]);

        $this->assertSame(4, $security->getHashInformation($hash)['options']['cost']);

        /**
         * A hash with the cost 31 takes too long. Thus examine the private
         * method that calculates the cost.
         */
        $method = new ReflectionMethod(Security::class, 'processCost');

        $this->assertSame(31, $method->invoke($security, ['cost' => 32]));
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17764
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-21
     */
    public function testEncryptionSecurityHashCostMissing(): void
    {
        $security = new Security();

        $hash = $security->hash('secret');

        $this->assertSame(10, $security->getHashInformation($hash)['options']['cost']);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-19
     *
     * @issue  https://github.com/phalcon/phalcon/issues/871
     */
    public function testEncryptionSecurityHashCostNumericString(): void
    {
        $security = new Security();

        $hash = $security->hash('secret', ['cost' => '5']);

        $this->assertSame(5, $security->getHashInformation($hash)['options']['cost']);
        $this->assertTrue($security->checkHash('secret', $hash));
    }
}
