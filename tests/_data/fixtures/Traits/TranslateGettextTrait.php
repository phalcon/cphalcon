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

namespace Phalcon\Tests\Fixtures\Traits;

use UnitTester;
use function dataDir;

trait TranslateGettextTrait
{
    /**
     * Executed before each test
     */
    public function _before(UnitTester $I)
    {
        $I->checkExtensionIsLoaded('gettext');

        if (!setlocale(LC_ALL, 'en_US.utf8')) {
            $I->skipTest('Locale en_US.utf8 not enabled');
        }
    }

    /**
     * @return array
     */
    protected function getGettextConfig(): array
    {
        return [
            'locale'        => ['en_US.utf8'],
            'defaultDomain' => 'messages',
            'directory'     => dataDir('assets/translation/gettext'),
            'category'      => LC_MESSAGES,
        ];
    }
}
