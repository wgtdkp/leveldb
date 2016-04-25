#include "leveldb/db.h"
#include "leveldb/dumpfile.h"
#include "leveldb/env.h"
#include "leveldb/filter_policy.h"
#include "leveldb/iterator.h"
#include "leveldb/options.h"
#include "leveldb/slice.h"
#include "leveldb/status.h"
#include "leveldb/table.h"
#include "leveldb/table_builder.h"
#include "leveldb/write_batch.h"

#include <iostream>
#include <string>
#include <cassert>

int main(void)
{
    leveldb::DB* db = NULL;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::WriteOptions writeOptions;
    leveldb::ReadOptions readOptions;
    leveldb::DB::Open(options, "test_db", &db);
    assert(db != nullptr);
    db->Put(writeOptions, "kangping", "23");
    db->Put(writeOptions, "xiaowei", "23");
    leveldb::Iterator* iter = db->NewIterator(readOptions);
    for (iter->SeekToFirst(); iter->Valid(); iter->Next()) {
        auto key = iter->key();
        auto val = iter->value();
        std::cout << key.ToString() << ": " << val.ToString() << std::endl;
    }
    //std::string age;
    //db->Get(readOptions, "kangping", &age);
    //std::cout << age << std::endl;
    delete db;
    return 0;
}
