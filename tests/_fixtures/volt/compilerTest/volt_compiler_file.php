<?php

/**
 * Fixture for Volt test
 *
 * @copyright (c) 2011-present Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Sergii Svyrydenko <sergey.v.svyrydenko@gmail.com>
 * @package   Phalcon\Test\Models
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

return [
    [
        [
            PATH_DATA . 'views/layouts/test10.volt.php'
        ],
        [
            PATH_DATA . 'views/layouts/test10.volt',
            PATH_DATA . 'views/layouts/test10.volt.php',
        ],
        PATH_DATA . 'views/layouts/test10.volt.php',
        '<?php if ($some_eval) { ?>
Clearly, the song is: <?= $this->getContent() ?>.
<?php } ?>',
    ],
];
