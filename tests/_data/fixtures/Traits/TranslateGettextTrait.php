<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Traits;

use UnitTester;
use function dataDir;

trait TranslateGettextTrait
{
    /**
     * Executed before each test
     */
    public function _before(UnitTester $I, $scenario)
    {
        $I->checkExtensionIsLoaded('gettext');

        if (!setlocale(LC_ALL, 'en_US.utf8')) {
            $scenario->skip('Locale en_US.utf8 not enabled');
        }
    }

    protected function getGettextConfig(): array
    {
        return [
            'locale'        => 'en_US.utf8',
            'defaultDomain' => 'messages',
            'directory'     => dataDir('assets/translation/gettext'),
            'category'      => LC_MESSAGES,
        ];
    }
}
