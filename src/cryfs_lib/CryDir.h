#pragma once
#ifndef CRYFS_LIB_CRYDIR_H_
#define CRYFS_LIB_CRYDIR_H_

#include <fspp/fs_interface/Dir.h>
#include "CryNode.h"

namespace cryfs {

class CryDir: public fspp::Dir, CryNode {
public:
  CryDir(CryDevice *device, const bf::path &path);
  virtual ~CryDir();

  //TODO return type variance to CryFile/CryDir?
  std::unique_ptr<fspp::File> createFile(const std::string &name, mode_t mode) override;
  std::unique_ptr<fspp::Dir> createDir(const std::string &name, mode_t mode) override;
  void rmdir() override;

  std::unique_ptr<std::vector<std::string>> children() const override;

private:
  DISALLOW_COPY_AND_ASSIGN(CryDir);
};

} /* namespace cryfs */

#endif